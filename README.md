# RandWeb

##The random links generator

RandWeb is a Console util which generates random links based on parameters (length, base link, additional commands) and open this random link in your borwser.

The input format: MIN_LENGTH, MAX_LENGTH, START_LINK_FRAGMENT (for example, google.com/), ADDITIONAL_COMMANDS

##The additional commands allow to filter the generated result. Additional commands should be included and separated via ;

###EXAMPLE: cmd1;cmd2;cmd3;

##Additional commands list:
* no-nums
* no-letters
* upper-case
* lower-case

(The list of parameters will be update when new parameters will be added in future)

## Default stuff
If you will not provide start link fragment, the start link fragment will be automatically google search

##Created by Daniel Oschepkov
