#!/bin/sh

output_name="app"

# enter build dir
cd build

# check for app build
if [ ! -f "${output_name}" ];then
  echo "[CMAKE] Run cmake ..."
  cmake ..
fi

echo "[MAKE] Make execuable app ..."
make
