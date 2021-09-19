#!/bin/sh
file=$1
# 引数を受け取りファイル名を抽出
fname=$(basename $file)
objfile=`echo $fname | sed 's/\.[^\.]*$//'`

echo "$file"
# ディレクトリに移動
cd $(dirname $file)
# g++ -g -o x $file -std=c++11
g++ $file -std=c++11

echo "in:"
cat ./test/sample-1.in
echo ""
echo "out:"
cat ./test/sample-1.in | ./a