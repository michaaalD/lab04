
//4.

#!usr/bash

find .  -type f -name '*~' | xargs -I {} rm -- {}

//5.
#!usr/bash
ls -t | head | grep $1
  
6.
#!/bin/bash
cd /home/mdos | ls -t lab* | head -1
  
//7.
#!/bin/bash
cd /home/mdos | sed 's/Christopher/Krzysiu/g' /home/mdos/lab04_pliki/.. kubus.txt 

8.

find .  -type f -name '$1'| sed '$2r $1'| mv "$1" "${1//.png/.jpg}
  
9.
#!usr/bash
cd /home/mdos | sed 'a/JPEG/jpg/g' 

10.
  
#!/bin/bash
echo Wskaz Katalog i podaj wymiary obrazu

for i in '*JPEG'
do
  mv -- "$i" "${i/%.JPEG/.jpg}"
done

for i in '*PNG'
do
  mv -- "$i" "${i/%.PNG/.png}"
done

convert $f -resize $2x$3 example.png

*/

//11.
#!/bin/bash
mail -s "Diablo" name_surname@student.pwr.edu.pl << "Diablo is alive!"

//12.
#!/bin/bash

# skrypt sprawdzajacy okresowo, czy jest zalogowany uzytkownik o podanym loginie
# wywolanie:  czy_jest login_uzytkownika

argc=$#            #dane, by pokazac sposob tworzenia zmiennych
                   #wokol operatora przypisania = nie moze byc zadnej spacji!!!

# sprawdzamy, czy podano wymagany argument 
if [ $argc -ne 1 ]; then  # [ ] - alternatywny sposob wywolywania polecenia test
                     # operator != porowna argumenty traktujac je jako napisy!!!
    echo "Wywolanie: $0 login_uzytkownika"
    exit 1
fi

# alternatywne sposoby sprawdzenia czy podano wymagany argument
#test $argc -ne 1 &&   echo "Wywolanie: $0 login_uzytkownika" && exit 1
#test $argc -eq 1 || { echo "Wywolanie: $0 login_uzytkownika" && exit 1; }


# dopoki nie ma uzytkownika usypiaj
while test `who |grep $1 |wc -l` -eq 0; do sleep 2; done

# uzytkownik pojawil sie - poinformuj
echo
echo -----------------
echo $1 pracuje 
echo -----------------
mail -s "$1" name_surname@student.pwr.edu.pl << "Uzytkownik $1 jest zalogowany"

exit 0



