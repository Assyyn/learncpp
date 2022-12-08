#!/bin/bash
###################################
# help
###################################
Help()
{
  # program usage
  # display help
  echo "Syntax: blcpp [-c|-l|-i|-r|-h]"
  echo "options:"
  echo "c     Build in current dir."
  echo "l     Build for learncpp/build."
  echo "i     Build and run executable."
  echo "r     Build, run and remove executable."
  echo "h     Print this Help."
}

###################################################
# build
###################################################
compilerArgs()
{
  # compiler arguments
  local args1='g++ -fdiagnostics-color=always -g -pedantic-errors -std=c++20'
  local args2="${fileName}"
  
  args="${args1} ${args2}"
  echo "${args}"
}

oName()
{
  echo "$(basename ${fileName} .cpp)"
}
###################################################
# Main program
###################################################
# Process the input options. Add options as needed. #
# ##################################################
# Get the options
while getopts ":hf:clir" option; do
  case $option in
    h) # display Help
      Help
      exit;;
    f) # Enter filename
      fileName=$OPTARG;;
    c) # build in current dir
      cx=$(compilerArgs)
      x=$(oName)
      ${cx} -o ${x}
      exit;;
    l) # build in learncpp/build/
      # maybe even cd to it in new terminal
      # in the future
      l=$(compilerArgs)
      ${l} -o /home/yuukii/dev/learncpp/build/$(oName)
      exit;;
    i) # build and run
      # status: incomplete
      echo "feature-incomplete!"
      exit;;
    r) # build, run, delete executable
      $(compilerArgs) -o $(oName)
      ./$(oName)
      rm $(oName)
      exit;;
    \?) # Invalid option
      echo "Error: Invalid Option"
      exit;;
  esac
done



