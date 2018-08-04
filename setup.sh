#!/bin/bash

cd scripts

echo "[coding-time] Testing JS ..."
./run_node.sh

echo "[coding-time] Testing C ..."
./build_for_linux.sh
./run_c.sh
