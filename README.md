# Librerías requeridas
1. sklearn.feature_extraction
2. sklearn.metrics
# Instrucciones para ejecutar el programa
Para ejecutar el programa se debe tener los directories del conjunto Q y R en el mismo path que el archivo extract_vectors.py
luego simplemente se debe ejecutar el archivo antes mencionado y este genera un archivo similitud.txt con los resultados

# descripcion breve del enfoque utilizado
Se utiliza tf-ifd  para el conjunto de Q junto con R con  un nrgram_range de 4,4 por lo que se extraen 4-gramas, luego calculados los valores de frecuencia de las ngramas
con tf-idf, se calcula la distancia coseno entre cada vectore de Q y todos los de R, y se retornan los 5 mas ceranos y se guarda el mas cercano para luego escribirlo en similitud.txt
