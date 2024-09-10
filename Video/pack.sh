ffmpeg -i input.mp4 -vcodec libx265 -crf 28 output.mp4

#!/bin/bash

data=./*
for f in $data
do
    v=$(echo $f | grep -P 'calc(?=.)' -o)$(echo $f | grep -P 'tor' -o)
    echo $v
done
