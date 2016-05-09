#!/bin/bash

echo 'building with: g++ -o example example.cc Employee.cc'
g++ -o example example.cc Employee.cc

if [ $? == 0 ]
then
    echo 'build finished'
    echo 'running example'
    ./example
else
    echo 'there was a build problem'
fi
