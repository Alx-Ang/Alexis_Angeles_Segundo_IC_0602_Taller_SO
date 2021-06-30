#!/bin/bash
ROOT_UID=0 #el idnentificador delm usuario root simpre es 0
SUCCESS=0

#verificar que este en modo root
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

#alamcenando el archivo enviado como parametro en la variabel file
file=$1
#verificar que el apartado de el archivo no este vacio
if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo del listado con Nombres de grupo a ingresar..."
   exit 1
fi

#verificar existencia de usuario
verificarUsuario(){
	usuario=$1
	id=$2
	#la -q significa quiet o silencio para que no imprima nanda
	if  grep -q "$usuario" /etc/passwd ;
	then
		#si esta
		return 1
	else
		#no esta
		return 0
	fi
}
#verificar existencia de grupo
verificarGrupo(){
	idgrupo=$1
        #la -q significa quiet o silencio para que no imprima nanda
        if  grep -q "$idgrupo" /etc/group;
        then
		#si esta
                return 1
        else
             	#no esta
                return 0
        fi
}
crearUsuario(){
	contra=$2
	echo "----------------------------------------------------"
	echo "El shell: $7"
	verificarUsuario "$1" "$3"
	if [ "$?" = "0" ];then
		echo "El usaurio [$1] no exite..."
		verificarGrupo "$4"
		if [ "$?" -eq "1" ];
		then
			if [ "$2" = "" ];
			then
				contra=$1
			fi
			echo "El Grupo [$4] si existe..."
			echo "Contrsena: $contra"
			echo "Directorio: $6"
			echo "USO DE BASH"
			if [ "$3" = "" ];
			then
				useradd -m -d $6 -c $5 -g $4 -s $7 -p $(echo $contra | openssl passwd -6 -stdin) $1
			else
				useradd -m -d $6 -c $5 -g $4 -s $7 -u $3 -p $(echo $contra | openssl passwd -6 -stdin) $1
			fi
			#permite pedir al primer inicio de sesion que cambie la contrasena
			chage -d 0 $1
			if [ $? -eq $SUCCESS ];
			then
				echo "USUARIO CREADO CORECTAMENTE !!!"
			else
				echo "ERROR AL CREAR EL USUARIO!!!"
			fi
		else
			echo "-> El grupo [$4] no se encuentra -> El <$1> no se puede crear"
		fi
	else
		echo "-> El usuario [$1] ya se encuentra creado -> El <$1> no se puede crear"
		echo "----------------------------------------------------"
	fi
}
#leer archivo
while IFS=: read nombre passw id gid info hdir cshell
do
	crearUsuario "$nombre" "$passw" "$id" "$gid" "$info" "$hdir" "$cshell"
done < ${file}

