make;
./a.out > a.txt;
cat a.txt | awk '{print $2}' > output.txt;
cat 19920104_091532.log | awk '{print $2}' > ans.txt;
diff output.txt ans.txt > diff.log;
if [[ `cat diff.log | wc -l` -eq 0 ]]; then
	printf "\033[32m%s\033[m\n" "OK";
else
	printf "\033[31m%s\033[m\n" "KO";
	cat diff.log;
fi
