cmake_minimum_required(VERSION 3.0.0)

# Simple multi-line content with bracket syntax, # no = needed between the square bracket markers 
set(multiLine [[ First line Second line ]])
# Bracket syntax prevents unwanted substitution 
set(shellScript [=[ #!/bin/bash
[[ -n "${USER}" ]] && echo "Have USER" ]=])
# Equivalent code without bracket syntax 
set(shellScript "#!/bin/bash
[[ -n \"\${USER}\" ]] && echo \"Have USER\" ")

