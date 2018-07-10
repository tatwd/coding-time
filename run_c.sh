#!/bin/bash

output_name="app"
extern_files=()
call_methods=()

readfiles () {
  i=0
  while read -r line
  do
    file=$(expr "$line" | grep -P '/* @file (.*) */' | sed 's/\/\* @file \(.*\) \*\//\1/g')
    if [ -n "$file" ];
    then
      extern_files[$i]="$file"
      let i++
    fi
  done < './main.c'
}

compiled () {
  return $(gcc ./main.c ${extern_files[*]} -o ${output_name}.exe)
}

running () {
  ./$output_name
}

# compiled program and runing
# compiled && running
echo "Read files and compiling..."
readfiles && compiled

echo -e "Start running test cases...\n"
# clear
running
