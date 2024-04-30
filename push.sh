#!/bin/bash
if [ $# -eq 0 ]
then 
    pushmessage=`date +%Y-%m-%d`
else
    pushmessage="$*"
fi

#pushmessage=`date +%Y-%m-%d`

echo ${pushmessage}

#git status;
git add -A; #添加所有的更新，.只能添加最新的更新
git commit -m "${pushmessage}";
git push -u origin master;
git push -u github master;

echo “成功”;
