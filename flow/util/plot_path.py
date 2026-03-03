import matplotlib.pyplot as plt
import pandas as pd
import re
import os
import argparse

def parse_netlist(lines):
    # Extract high-level description
    high_level_info = {}
    high_level_keys = ['Startpoint', 'Endpoint', 'Path Group', 'Path Type', 'Corner']
    for key in high_level_keys:
        for line in lines:
            if line.startswith(key):
                high_level_info[key] = line.split(':', 1)[1].strip()
                break

    # Extract netlist data
    netlist_data = []
    data_section = False
    no_fanout_cap_elements = []  # List to store elements with no fanout and cap
    for line in lines:
        if line.startswith("Fanout"):
            data_section = True
            continue
        if data_section and line.strip() == "":
            break
        if data_section:
            # Match the data line
            match = re.match(r'(\d+)\s+([\d.]+)\s+([\d.]+)\s+([\d.]+)\s+([\d.]+)\s+(.*)', line)
            if match:
                netlist_data.append(match.groups())
            else:
                # Check for lines with no fanout and cap
                no_fanout_cap_match = re.match(r'\s+([\d.]+)\s+([\d.]+)\s+([\d.]+)\s+([\d.]+)\s+([\d.]+)\s+(.*)', line)
                if no_fanout_cap_match:
                    # Extract the relevant data
                    no_fanout_cap_elements.append(no_fanout_cap_match.groups())

    # Create a DataFrame for easier manipulation
    columns = ['Fanout', 'Cap', 'Slew', 'Delay', 'Time', 'Description']
    df = pd.DataFrame(netlist_data, columns=columns)
    df['Time'] = df['Time'].astype(float)  # Convert Time to float for plotting

    # Extract additional variables
    data_required_time = None
    data_arrival_time = None
    slack = None

    for line in lines:
        if "data required time" in line:
            data_required_time = float(line.split()[0])  # Extract the numeric value
        elif "data arrival time" in line:
            data_arrival_time = float(line.split()[0])  # Extract the numeric value
        elif "slack" in line:
            slack_value = line.split()[0]
            if slack_value.startswith('-'):
                slack = float(slack_value)  # Handle negative slack
            else:
                slack = float(slack_value)  # Handle positive slack

    # Add additional columns to the DataFrame
    df['Data Required Time'] = data_required_time
    df['Data Arrival Time'] = data_arrival_time
    df['Slack'] = slack

    # Add elements with no fanout and cap to the DataFrame
    for element in no_fanout_cap_elements:
        df = df.append(pd.Series(element, index=df.columns), ignore_index=True)

    return high_level_info, df

def plot_netlist(high_level_info, df, netlist_index, output_path):
    plt.figure(figsize=(12, 8))

    # Plot high-level description
    plt.title(f"Netlist Path: {high_level_info['Startpoint']} to {high_level_info['Endpoint']}")
    plt.xlabel('Element Index')
    plt.ylabel('Time (ns)')
    
    # Plot each point in the netlist
    plt.plot(df.index, df['Time'], marker='o', linestyle='-', color='b', label='Data Arrival Time')

    # Annotate each point with its description
    for i, row in df.iterrows():
        plt.annotate(row['Description'], (i, row['Time']), textcoords="offset points", xytext=(0,10), ha='center')

    plt.axhline(y=df['Time'].max(), color='r', linestyle='--', label='Max Time')
    plt.axhline(y=df['Time'].min(), color='g', linestyle='--', label='Min Time')
    
    plt.legend()
    plt.grid()
    
    # Save the plot as a PNG file in the specified output path
    output_file = os.path.join(output_path, f'netlist_plot_{netlist_index}.png')
    plt.savefig(output_file)
    plt.close()

def main(file_path, output_path):
    with open(file_path, 'r') as file:
        content = file.read()

    # Split the content into netlist sections based on the "Startpoint" keyword
    netlists = content.split("Startpoint:")[1:]  # Skip the first part before the first netlist

    for index, netlist in enumerate(netlists):
        # Prepend "Startpoint:" back to the netlist section
        netlist = "Startpoint:" + netlist
        lines = netlist.splitlines()
        
        # Remove carriage return characters and strip whitespace
        lines = [line.replace('\r', '').strip() for line in lines]

        # Parse the netlist
        high_level_info, df = parse_netlist(lines)
        
        # Plot and save the netlist
        plot_netlist(high_level_info, df, index + 1, output_path)

        # Optionally, display the DataFrame after parsing
        print(f"DataFrame for netlist {index + 1}:")
        print(df)

if __name__ == "__main__":
    # Set up command-line argument parsing
    parser = argparse.ArgumentParser(description='Process netlist file and generate plots.')
    parser.add_argument('file_path', type=str, help='Path to the netlist file')
    parser.add_argument('output_path', type=str, help='Directory to save the output plots')
    
    args = parser.parse_args()
    
    # Ensure the output directory exists
    os.makedirs(args.output_path, exist_ok=True)
    
    # Call the main function with the provided arguments
    main(args.file_path, args.output_path)
