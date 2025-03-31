import subprocess
import re
import sys

def ping(host):
    # Execute the ping command
    try:
        # For Windows, use 'ping -n 4' and for Unix/Linux, use 'ping -c 4'
        command = ['ping', '-c', '4', host]  # Change '-c' to '-n' for Windows
        output = subprocess.check_output(command, universal_newlines=True)
        
        # Print the output for debugging
        print(output)

        # Use regex to find the round trip time
        rtt_pattern = re.compile(r'time=(\d+\.\d+) ms')
        rtt_values = rtt_pattern.findall(output)

        if rtt_values:
            # Convert RTT values to float and calculate average
            rtt_values = [float(rtt) for rtt in rtt_values]
            average_rtt = sum(rtt_values) / len(rtt_values)
            print(f'Average Round Trip Time: {average_rtt:.2f} ms')
        else:
            print('No RTT values found.')

    except subprocess.CalledProcessError as e:
        print(f'Error occurred while pinging {host}: {e}')

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python ping_rtt.py <host>")
        sys.exit(1)

    host_to_ping = sys.argv[1]
    ping(host_to_ping)
