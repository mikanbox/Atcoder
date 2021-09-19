#!/bin/sh
file=$1
# 引数を受け取りファイル名を抽出
fname=$(basename $file)
objfile=`echo $fname | sed 's/\.[^\.]*$//'`

echo "$file"
# ディレクトリに移動
cd $(dirname $file)

echo "テストケースURLを記載(ex : https://atcoder.jp/contests/abc156/tasks/abc156_b)"
read str 
if [ -e ./a.out ]; then
  rm ./a.out
fi


g++ -o $file  -std=c++11

rm -r ./test
oj dl $str

oj t --jobs 3 -c "./a.out" 