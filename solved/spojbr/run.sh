prob=alvo
#subdir=test
subdir=

for i in `seq 1 1 10`
do
	for j in `seq 1 1 10`
	do
		echo $i $j
		./a.out <$prob/$subdir$i/in$j >out.txt
		diff $prob/$subdir$i/out$j out.txt
	done

done
