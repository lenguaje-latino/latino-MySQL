# Latino-MySQL
![GitHub release (latest by date)](https://img.shields.io/github/v/release/MelvinG24/Latino-MySQL)
![GitHub](https://img.shields.io/github/license/MelvinG24/Latino-MySQL)

Esta librería nos permite conectar y trabajar con base de datos MySQL usando *Latino* como lenguaje.

>Esta librería está desarrollada para trabajar en conjunto con *Latino* (Un lenguaje de programación con sintaxis al Español). Para mayor información sobre este lenguaje de programación visite el repositorio oficial del lenguaje [aquí](https://github.com/lenguaje-latino/Latino/)

## Requisitos
Los requisitos para ulitizar esta librería son los siguientes: 
|Software|Enlaces|
|---|---|
|Latino (^1.0.0)|[Descargar](https://github.com/lenguaje-latino/Latino/releases)|
|MySQL (Sólo Windows)|[Descargar](https://dev.mysql.com/downloads/windows/installer/)|
|MySQL (Mac)|[Descargar](https://dev.mysql.com/downloads/mysql/)|
|MySQL (Sólo Linux)|[Descargar](https://dev.mysql.com/doc/refman/8.0/en/linux-installation.html)|

# Instalación de la librería Latino-MySQL
Antes de hacer nada, necesitamos tener *Latino* y MySQL instalados en nuestro sistema. Una vez tengamos ambos programas instalados pasaremos a instalar la Librería de Latino-MySQL.

|Descripción|Enlaces|
|---|---|
|Instalador de Latino-MySQL (Win, Mac) |[Descargar](https://github.com/MelvinG24/Latino-MySQL/releases)| 
|En **Linux** esta librería se instala de forma manual|[Aquí](#linuxUbuntu)|

### :warning: Nota para los usuarios de MacOS
> En MacOS si la instalación presenta problemas de seguridad por ser un desarrollador desconocido, estos son los pasos a seguir:<br/>
> Abrimos "**System Preferences**"<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|--> "**Security and Privacy**"</br>
> y llegado aquí damos permiso al sistema de ejecutar la instalación de Latino-MySQL

<a name="linuxUbuntu"></a>
## Instalación de Latino-MySQL en Ubuntu
Primero pasamos a instalar MySQL y despues la librería de Latino-MySQL en nuestro sistema.

### Instalación de MySQL en Ubuntu
```bash
#instalacion en ubuntu
sudo apt-get install mysql-server mysql-client libmysqlclient-dev
```
### Instalación de la librería en linux
```bash
git clone https://github.com/lenguaje-latino/Latino-MySQL
cd latino-mysql
sudo chmod +x instalar.sh
sudo bash instalar.sh
```

# Uso de esta librería en código Latino
```sql
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
# Desinstalar Latino-MySQL
* [Desinstalar en Windows](#desWin)
* [Desinstalar en Mac](#desMac)
* [Desinstalar en Linux](#desLx)

<a name="desWin"></a>
### Desinstalar en Windows

<a name="desMac"></a>
### Desinstalar en Mac
Para desinstalar la librería de Latino-MySQL en Mac estos son los pasos a seguir:
1. Doble-clic en nuestro paquete de instalación Latino-MySQL-XXX-Darwin.pkg.
2. Una vez nuestra imagen sea montada en nuestro escritorio hacemos doble-clic para abrir.
3. Doble-clic en la carpeta llamada **Extras**.
4. Abrimos nuestra Terminal en Mac.
5. Escribimos **sudo sh ** (le dejamos un espacio al final).
6. Agaramos y soltamos nuestro archivo **uninstall.sh** en nuestra Terminal.
    Ejemplo:
	    **$ sudo sh /Volumes/Latino-MySQL-XXX-Darwin/Extras/uninstall.sh**
7. Presionamos **Enter** para correr el comando y procedemos con insertar nuestra contraseña de administrador.

<a name="desLx"></a>
### Desinstalar en Linux

# Ayuda y Documentación
*Latino* dispone de un foro en su página web oficial, así como también un grupo en Telegram, Gitter y una documentación a la que puedes dirigirte en caso de cualquier duda.
- [Página Oficial](https://www.lenguajelatino.org)
- [Manual Latino](https://manual-latino.readthedocs.io/es/latest/)
- [Stack Overflow](https://es.stackoverflow.com/questions/tagged/latino)
- [Chat en Gitter](https://gitter.im/primitivorm/latino?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
- [Chat en Telegram](https://t.me/joinchat/AAAAAD6l6_qIgQAAgu9DVQ)

# Licencia
Licenciado bajo la licencia [MIT](https://github.com/MelvinG24/Latino-MySQL/blob/master/LICENSE)<br/>
Cualquier aportación o sugerencia es bienvenida
