### latino-mysql
Libreria dinamica para conectar con la base de datos mysql en [latino](https://github.com/primitivorm/latino)

##### Prerequisitos
Tener instalado [latino](https://github.com/primitivorm/latino)

### Instalación
##### linux
```
git clone https://github.com/primitivorm/latino-mysql
cd latino-mysql
sudo chmod +x instalar.sh
sudo bash instalar.sh
```

#### Dependecias
[mysql](https://dev.mysql.com/doc/refman/8.0/en/linux-installation.html)
```
#instalacion en ubuntu
sudo apt-get install mysql-server mysql-client libmysqlclient-dev
```

##### Uso de esta librería en código latino
```
//importa la libreria latino-mysql
incluir("mysql")

//crea la conexion al servidor de base de datos: localhost
//con usuario: root y password : 12345678 y la base de datos : sakila
con = mysql.conectar("localhost", "root", "12345678", "sakila")

//consulta que se ejecutara
sql = "select first_name, last_name from actor"	// limit 10;

//executa la consulta
resultado = mysql.consultar(con, sql)

//obtiene el numero de filas del resultado
nfilas = mysql.numero_filas(resultado)
imprimir("numero de filas: " .. nfilas)

//muestra el encabezado
imprimir("first_name\t\tlast_name")

//obtener la informacion de todas la filas de la consulta
desde(i=0; i< nfilas;i++)
	//extrae la informacion de la fila
	datos = mysql.extraer_fila(resultado)

	//muestra la informacion en consola
	imprimir(datos["first_name"] .. "\t\t" .. datos["last_name"])
fin

//cierra la desconexion a base de datos
mysql.desconectar(con)
```

##### Cualquier aportación o sugerencia es bienvenida
