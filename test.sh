nMin=1
nMax=12

kMin=0
kMax=3

klMin=0
klMax=100

g=10000
valgr=false
all=0 # [0/1] - czy wyswietlac posrednie ilosci
forceContinue=false # quit on error

RED='\033[0;31m'
NC='\033[0m' # No Color

while getopts vafg:* flag
do
    case "${flag}" in
        v) valgr=true;;
        a) all=1;;
        g) g=$OPTARG;;
        f) forceContinue=true;;
    esac
done

echo -e "Paramatry testu: n: [$nMin, $nMax], k: [$kMin, $kMax], g: $g, a: $all, v: $valgr, f: $forceContinue\n" > ./log.txt
g++ @opcjeCpp wys.cpp testerka.cpp -o wys.e

for n in $(seq $nMin $nMax)
do
    for k in $(seq $kMin $kMax)
    do
        for kl in $(seq $klMin $klMax)
        do
            seed=$(( ((($k*100) + $n) * 1000) + $kl))
            input="$n $k $g $kl $all $seed\n"
            echo -ne "Aktualne parametry: $input"
            if [ "$valgr" = false ]
            then
                ./wys.e <<< $input >> ./log.txt
            else
    	        valgrind -q --exit-on-first-error=yes --error-exitcode=-1 --log-file=memcheck.log --tool=memcheck --leak-check=yes ./wys.e <<< $input >> ./log.txt
            fi

            if [[ $? != 0 && "$forceContinue" = false ]]
            then
                echo -e "${RED}BLAD${NC}"
                exit -1
            fi

        done

    done

done

