# Simply print HELP message
msg='\033[38;5;214m\n\
\n *************************************************************\n\
\n *************************** HELP ****************************\n\
\n *************************************************************\n\
\n - HJSON SETUP\
\n   .Run "make hjson" to create the .hjson template which \
\n    will be used to generate both doc and regmap\n\
\n - DOCUMENTATION\
\n   .Run "make doc" to generate the markdown documentation file\
\n    from the hjson file created before\n\
\n - REGMAP\
\n   .Run "make reg" to generate the regmap file for SoC integration\
\n    with TLUL interconnect based system\
\033[0;0m'
print(msg)
