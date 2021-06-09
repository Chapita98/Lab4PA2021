- Lab0PA
- Primero lo clonas en una carpeta designada por ti
`git clone https://github.com/Chapita98/Lab4PA2021.git`

- Muevete a ese directorio con el comando cd

- Luego te fijas si tienes una inicializacion de git
`git remote -v`

- Si no la tienes haz:
`1. git init`

`2. git remote add origin https://github.com/Chapita98/Lab4PA2021`

- Para ver los cambios que hiciste:
`git status`

- Para añadir a un paquete esos cambios
`git add .`

- Para hacer COMMIT
`git commit -m "Breve mensaje diciendo que hiciste"`

- Para hacer PUSH
`git push origin master // Si master no es tu rama entonces cambialo a tu rama`

- Crear una nueva rama
`git branch eugenio`

- Ver lista de ramas
`git branch`

- Cambiar a una rama
`git checkout eugenio`

- Para Hacer PULL
`1. git fetch --all`

`2. git pull origin master`

- Si quieres empezar todo desde 0
`1. git fetch --all`

`2. git reset --hard origin/master`

-Instrucciones para uso de archivo Makefile

1 - Abrir la terminal como root
2 - Posicionarse en la carpeta donde estar los archivos .cpp y .h
3 - Ejecutar comando:    'chmod +x Makefile.sh'     (o bien    'chmod 777 Makefile.sh')
4 - Asegurarse que no existan archivos .o antiguos con el comando:    'make clean'
5 - Crear archivos .o con el comando:    'make'
6 - Ejecutar programa con el comando:    './Lab0PA
7 - Una vez usado el programa, limpiar los archivos .o creados con el comando:    'make clean'
extra - Hacer 'make rebuild' (hace automaticamente  'make clean', y despues 'make')
