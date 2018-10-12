/*
The MIT License (MIT)

Copyright (c) Latino - Lenguaje de Programacion

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 */

// Referencia API Mysql : https://dev.mysql.com/doc/refman/5.6/en/c-api.html
#include <mysql.h>

#define LATINO_LIB

#include <latino.h>
#include <latobj.h>

#define LIB_MYSQL_NAME "mysql"

static void mysql_conectar(lat_mv *mv) {  
  MYSQL mysql;
  mysql_init(&mysql);
  lat_objeto *db = latC_desapilar(mv);
  lat_objeto *p = latC_desapilar(mv);
  lat_objeto *u = latC_desapilar(mv);
  lat_objeto *h = latC_desapilar(mv);
  const char *host = latC_checar_cadena(mv, h);
  const char *user = latC_checar_cadena(mv, u);
  const char *passwd = latC_checar_cadena(mv, p);
  const char *database = latC_checar_cadena(mv, db);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "latino");
  if (!mysql_real_connect(&mysql, host, user, passwd, database, 0, NULL, 0)) {
    fprintf(stderr, "Failed to connect to database: Error: %s\n",
            mysql_error(&mysql));
  }
}
static void mysql_num_filas(lat_mv *mv) {}
static void mysql_cerrar(lat_mv *mv) {}

static const lat_CReg libmysql[] = {{"conectar", mysql_conectar, 4},
                                    {"numero_filas", mysql_num_filas, 1},
                                    {"cerrar", mysql_cerrar, 1},
                                    {NULL, NULL, 0}};

LATINO_API void latC_abrir_liblatino_mysql(lat_mv *mv) {
  latC_abrir_liblatino(mv, LIB_MYSQL_NAME, libmysql);
}
