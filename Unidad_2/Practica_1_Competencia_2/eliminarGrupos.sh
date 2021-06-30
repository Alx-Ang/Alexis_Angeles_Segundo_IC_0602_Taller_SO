#!/bin/bash
ROOT_UID=0
SUCCESS=0

if [ "$UID" -ne "$ROOT_UID" ];
then
	echo "Se debe estar como root para ejecutar este script";
	exit $E_NOROOT
fi

file=$1

#verficacion de que se ingrese le archivo
if [ "${file}X" = "X" ];
then
	echo "Debe indicar el archivo del listado con Nombres de grupo a ingresar...";
	exit 1
fi

#fucnicion que elinminara el grupo
eliminar(){
	grupo=$1
	groupdel $grupo
	if [ "$?" -ne "$SUCCESS" ];
	then
		echo "EL GRUPO [$grupo] no se boorro !!!"
		echo "___________________________________________"
	else
		echo "EL GRUPO [$grupo] se borro corectamente!!!!"
		echo "___________________________________________" 

	fi
}

while IFS=: read grupo
do
	eliminar "$grupo"
done < $file
