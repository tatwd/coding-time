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
  if [ -f "${output_name}.exe" ];then
    rm ${output_name}.exe
  fi

  echo "Read files and compiling..."
  readfiles
  $(gcc ./main.c ${extern_files[*]} -o ${output_name}.exe)
}

running () {
  if [ -f "${output_name}.exe" ];then
    echo -e "Start running test cases...\n"
    ./$output_name
  else
    echo "Failed compiling your code!"
  fi
}

# compiled
compiled

# running
running
