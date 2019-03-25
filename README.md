
Sebastian Donoso Bustos
realice y corri la tarea en un MacBook air SO:macOs High Sierra version 10.13.6
 con el IDE CLion

utilice opencv-3.4.2
INTRUCCIONES PARA COMPILAR
con la terminal en el directorio de la tarea se debe hacer:
$ cmake .
$ cmake --build .


INTRUCCIONES PARA EJECUTAR

Los argumentos que se deben entregar al ejecutar t1_comerciales son:
-"0" o "1" : un "0" si es la primera vez que se cargaran los comerciales un "1" si ya se cargaron una vez

-"directorio donde están los comerciales": siempre debe ir este parámetro aun que ya se hayan cargado ya que en el mismo directorio se guardan las características

-"dirección del video" : es la dirección del video que se desea cargar para comparar con los comerciales

-"nombre del video sin la extensión .mp4": esto es el nombre que se entregara en el txt

Ejemplo de ejecución : 
$./t1_comerciales "0" "dircc comerciales" "dircc video" "nombre video"

EN EJECUCION:
mientras se esta ejecutando el programa primero se verán los directorios de los comerciales si es que estos se están extrayendo, luego van a apareciendo el numero de frames del video esta parte es la que tiene mayor duración, cuando termina la extracción de frames del video, comienza la comparación al final de esto se genera el archivo detecciones.txt
