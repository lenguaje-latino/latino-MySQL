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
  MYSQL *mysql = malloc(sizeof(MYSQL));
  mysql_init(mysql);
  lat_objeto *db = latC_desapilar(mv);
  lat_objeto *p = latC_desapilar(mv);
  lat_objeto *u = latC_desapilar(mv);
  lat_objeto *h = latC_desapilar(mv);
  const char *host = latC_checar_cadena(mv, h);
  const char *user = latC_checar_cadena(mv, u);
  const char *passwd = latC_checar_cadena(mv, p);
  const char *database = latC_checar_cadena(mv, db);
  if (!mysql_real_connect(mysql, host, user, passwd, database, 0, NULL, 0)) {
    latC_error(mv, "latino-mysql error: %s", mysql_error(mysql));
  }
  lat_objeto *res = latC_crear_cdato(mv, mysql);
  latC_apilar(mv, res);
}

static void mysql_consultar(lat_mv *mv) {
  lat_objeto *query = latC_desapilar(mv);
  lat_objeto *con = latC_desapilar(mv);
  char *strQuery = latC_checar_cadena(mv, query);
  MYSQL *mysql = (MYSQL *)con->val.cpointer;
  int r = mysql_query(mysql, strQuery);
  if (r == 0) {
    MYSQL_RES *obj;
    obj = malloc(sizeof(MYSQL_RES));
    obj = mysql_store_result(mysql);
    lat_objeto *res = latC_crear_cdato(mv, obj);
    latC_apilar(mv, res);
  } else {
    latC_error(mv, "latino-mysql error: %s", mysql_error(mysql));
  }
}

static void mysql_desconectar(lat_mv *mv) {
  lat_objeto *con = latC_desapilar(mv);
  MYSQL *mysql = (MYSQL *)con->val.cpointer;
  mysql_close(mysql);
}

static void mysql_extraer_fila(lat_mv *mv) {
  lat_objeto *obj = latC_desapilar(mv);
  MYSQL_RES *res = (MYSQL_RES *)obj->val.cpointer;
  MYSQL_ROW row = mysql_fetch_row(res);
  unsigned int num_fields;
  unsigned int i;
  unsigned long *lengths;
  num_fields = mysql_num_fields(res);
  lengths = mysql_fetch_lengths(res);
  hash_map *map = latH_crear(mv);
  for (i = 0; i < num_fields; i++) {
    MYSQL_FIELD field = res->fields[i];
    lat_objeto *key = latC_crear_cadena(mv, field.name);
    lat_objeto *value = latC_crear_cadena(mv, row[i]);
    latH_asignar(mv, map, latC_astring(mv, key), value);
  }
  lat_objeto *dic = latC_crear_dic(mv, map);
  latC_apilar(mv, dic);
}

static void mysql_filas_afectadas(lat_mv *mv) {
  lat_objeto *obj = latC_desapilar(mv);
  MYSQL *res = (MYSQL *)obj->val.cpointer;
  unsigned long long num = mysql_affected_rows(res);
  latC_apilar_double(mv, (double)num);
}

static void mysql_num_filas(lat_mv *mv) {
  lat_objeto *obj = latC_desapilar(mv);
  MYSQL_RES *res = (MYSQL_RES *)obj->val.cpointer;
  unsigned long long num = mysql_num_rows(res);
  latC_apilar_double(mv, (double)num);
}

static void mysql_num_columnas(lat_mv *mv) {
  lat_objeto *obj = latC_desapilar(mv);
  MYSQL_RES *res = (MYSQL_RES *)obj->val.cpointer;
  unsigned long long num = mysql_num_fields(res);
  latC_apilar_double(mv, (double)num);
}

static const lat_CReg libmysql[] = {
    {"conectar", mysql_conectar, 4},
    {"consultar", mysql_consultar, 2},
    {"desconectar", mysql_desconectar, 1},
    {"extraer_fila", mysql_extraer_fila, 1},
    {"filas_afectadas", mysql_filas_afectadas, 1},
    {"numero_filas", mysql_num_filas, 1},
    {"numero_columnas", mysql_num_columnas, 1},

    {NULL, NULL, 0}};

LATINO_API void latC_abrir_liblatino_mysql(lat_mv *mv) {
  latC_abrir_liblatino(mv, LIB_MYSQL_NAME, libmysql);
}
