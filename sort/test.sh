#!/bin/bash

cwd=`pwd`
input_dir=${cwd}"/dataset"
execute=${cwd}"/python/sort.py"
output_dir=${cwd}"/dataset/output"

rm $output_dir/*

for input_abs in `ls ${input_dir}/*unsorted*`; do
	filename=${input_abs##*/}  #remove /xxxx/xxx/
	size=${filename%%_*}   #remove _xxxx
	output=${size}".out"
	output_abs=${output_dir}"/"${output}
	$execute $input_abs $output_abs
done

cd $output_dir
for file in `ls`; do
	size=${file%%_*}
	algorithm=${file##*_}
	algorithm=${algorithm%%.*}
	sorted="../"${size}"_sorted.data"

	if diff $file $sorted > /dev/null; then
		#echo $size ":" $algorithm "sort: success!"
		printf "%8d: %9s sort: success!\n" $size $algorithm
	else
		#echo $size ":" $algorithm "sort: failed!"
		printf "%8d: %9s sort: failed!\n" $size $algorithm
	fi
done

