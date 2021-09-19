#!/bin/sh
file=$1
# 引数を受け取りファイル名を抽出
fname=$(basename $file)
objfile=`echo $fname | sed 's/\.[^\.]*$//'`

echo "$file"
# ディレクトリに移動
cd $(dirname $file)

if [ -e ./a.out ]; then
  rm ./a.out
fi


# g++ -g -o x $file -std=c++11
g++ $file -std=c++11


echo "test : "
oj t
