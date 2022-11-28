#!/bin/bash

port=${1}
file=${2}
echo $port
echo $file

python ./ST_NUM/t190008/httpServer2.py $[$port] ${file}
python ./httpTestClient.py $[$port] ${file}

echo test
