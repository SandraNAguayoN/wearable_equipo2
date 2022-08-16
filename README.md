# Proyecto Pulsera Multiuso
[![Contribuidores][contribuidores-shield]][contributors-url]

## contenido
<details>
  <summary>Tabla contenidos</summary>
  <ol>
    <li>
      <a href="#acerca-del-proyecto">Acerca Del Proyecto</a>
      <ul>
        <li><a href="#nombre-del-proyecto">Nombre del proyecto</a></li>
        <li><a href="#descripcion-general-del-proyecto">Descripción general del proyecto</a></li>
      </ul>
    </li>
    <li>
        <a href="#objetivo-del-proyecto">Objetivo del proyecto</a>
    </li>
    <li>
        <a href="#vision-del-proyecto">Visión del proyecto</a>
    </li>
    <li>
        <a href="#material-de-uso">Material de uso</a>
    </li>
    <li>
        <a href="#epicas">Épicas</a>
    </li>
    <li>
        <a href="#requerimientos">Requerimientos</a>
    </li>
    <li>
        <a href="#diagrama-inicial">Diagrama inicial</a>
    </li>
    <li>
        <a href="#prototipo-de-pulsera-multiusos">Prototipo de Pulsera Multiusos</a>
    </li>
    <li>
        <a href="#tablero">Tablero</a>
    </li>
    <li>
        <a href="#resultados">Resultados</a>
    </li>
    <li>
      <a href="#participantes">Participantes</a>
    </li>
  </ol>
</details>

<!-- Acerca del proyecto -->
## Acerca del proyecto

### Nombre del proyecto
**Pulsera Multiusos**

### Descripción general del proyecto
> Este proyecto consiste generar un prototipo que propone ser un accesorio tecnológico para las personas, de forma que recolecte datos a través de los distintos sensores, y los use para su posterior análisis validando decisiones del usuario.

## Objetivo del proyecto
> El objetivo del proyecto es fabricar un accesorio de uso personal el cual es una pulsera tecnológica que permita a los usuarios medir la temperatura, humedad y oxigenación en la sangre, guardando todo estos datos y mostrandolos en una pequeña pantalla, de la misma forma el usuario podrá acceder a una aplicación web en línea con sus credenciales, en la cual podrá visualizar los datos mencionados en tiempo real.

## Visión del proyecto
> Nuestra visión llegar a ser una empresa líder en la fabricación y distribución de accesorios tecnológicos de uso personal a nivel regional en el municipio de Dolores Hidalgo para después expandirnos a nivel estatal en el estado de Guanajuato y por consecuencia a nivel nacional ne México.

## Librerias
* Adafruit_GFX.h
* Adafruit_SSD1306.h
* DHTesp.h
* EasyBuzzer.h
* Esp_camera.h
* FirebaseESP32.h
* HeartRate.h
* MAX30105.h
* Pgmspace.h
* Soc.h
* WiFiClientSecure.h
* WiFi.h

## Requerimientos
<table>
  <tr>
    <th>Software</th>
      <th>Licencia</th>
  </tr>
  <tr>
    <td>Arduino</td>
    <td>Licencia Pública General</td>
  </tr>
  
  <tr>
    <td>Firebase</td>
    <td>modelo de precios de pago por uso.  
      <ul>
        <li>Almacenamiento en base de datos $0.18 por GB</li>
        <li>Almacenamiento $0.026 por GB </li>
      </ul>
    </td>
  </tr>
  
  <tr>
    <td>Google Drive</td>
    <td>
      <ul>
        <li>Licencia gratuita</li>
        <li>Planes de pago</li>
      </ul>
    </td>
  </tr>
</table>
## Software
* Arduino
* Api Firebase
* Google script

## Hardware:
<table> <tr> <th>Componente</th><th>Imagen</th><th>Descripción</th><th>Cantidad</th></tr> 
  <tr>
    <td>ESP32 Cam</td>
    <td>
    <img src="https://user-images.githubusercontent.com/36056832/165996397-e9527b13-6ad4-4e73-a732-7721e0ffac59.png"  alt="ESP32 Cam" width="100"/>
    </td>
    <td><ul><li>Voltaje: 5 V<li>CPU de 32 bits de doble núcleo de baja potencia para procesadores de aplicaciones<li>Frecuencia principal de hasta 240 MHz<li>Potencia de cálculo de hasta 600 DMIPS<li>SRAM integrado de 520 KB<li>PSRAM externo de 4 M<li>Es ideal para interfaces como: UART. SPI. I2C. PWM. ADC. DAC<li>Soporta cámaras OV2640 y OV7670 (flash incorporado)<li>Apoyo imagen WiFi subir<li>Apoyo TF tarjeta</ul></td>
    <td>1</td>
  </tr> 
  <tr>
    <td>Sensor DHT11</td>
    <td>
    <img src="https://user-images.githubusercontent.com/36056832/165996618-0b719509-9c81-405a-bef5-aabef6623a2b.png" alt="DHT11" width="100"/>
    </td>
    <td> <ul><li>Alimentación: 3.3 ~ 5 V<li>Rango de medición de temperatura: 0 ~ 50 °C<li>Precisión de medición de temperatura: ± 2.0 °C<li>Resolución Temperatura: 0.1 °C<li>Rango de medición de humedad: 20 % ~ 90 % RH<li>Precisión de medición de humedad: 4 % RH<li>Resolución Humedad: 1 % RH<li>Salida digital<li>Orificio de perno fijo para una fácil instalación</ul></td>
    <td>1</td>
  </tr> 
  <tr>
    <td>Pantalla OLED SSD1306</td>
    <td>
    <img src="https://user-images.githubusercontent.com/28987470/173898074-3669ca53-a985-4243-b21e-d4180c152393.png" alt="OLED" width="100"/>
    </td>
    <td> <ul><li>Resolucion: 128X64<li>Tamaño: 0.96 " - 26x14mm<li>Interface: I2C<li>Voltaje de Operacion: 3.3-5v<li>Angulo de Vision: 160°</ul></td>
    <td>1</td>
  </tr> 
  <tr>
    <td>Sensor de Oxigenación </td>
    <td>
    <img src="https://user-images.githubusercontent.com/28987470/173898515-e6732d31-cfe5-423a-88eb-f6b3a6c00c00.png" width="100"/>
    </td>
    <td> <ul><li>Tensión de Alimentación: 3.3V a 5V<li>Longitud Máxima de Onda LED: 660nm/880nm<li>Corriente de trabajo: 60mA<li>Tipo de detección: PPG (Reflexión de luz)<li>Interface de salida: I2C<li>Dimensiones:21 mm x 15mm<li>ADC delta sigma de hasta 16 bits</ul></td>
    <td>1</td>
  </tr> 
    <tr>
    <td>Sensor Ultrasonico </td>
    <td>
    <img src="https://github.com/SandraNAguayoN/wearable_equipo2/blob/main/img/ultrasonico.jpg" width="100"/>
    </td>
      <td> <ul><li>Voltaje de funcionamiento: 5V(DC)</li><li>Corriente estática: menos de 2 mA.</li><li>Señal: señal de frecuencia eléctrica, alto nivel 5V, 0V de nivel bajo.</li><li>Ángulo sensor: no más de 15 grados.</li><li>Distancia detección: 2cm ~ 450cm.</li>Alta precisión: hasta 3mm</li><li>Modo de conexión: VCC / trig(T) / echo(R) / GND</li><li>Módulo Principio de trabajo:</li><li>El módulo automáticamente envia una onda cuadrada de 40khz y detecta automáticamente la señal de pulso que regresa.</li></ul></td>
    <td>1</td>
  </tr> 
  <tr>
    <td>Buzzer</td>
    <td>
    <img src="https://github.com/SandraNAguayoN/wearable_equipo2/blob/main/img/buzzer.png" width="100"/>
    </td>
      <td><ul><li>Voltaje: 3.5 - 5 V</li><li>Corriente: <25mA</li><li>Frecuencia: 500-2300 Hz</li><li>Tono: Constante<li>Diámetro: 16mm</li><li>Altura: 10mm</li>
        </ul>
      </td>
    <td>1</td>
  </tr> 
  <tr>
    <td>Push button 4 pines con capuchon</td>
    <td>
    <img src="https://github.com/SandraNAguayoN/wearable_equipo2/blob/main/img/button.webp" width="100"/>
    </td>
      <td><ul><li>Para 50 mA de corriente</li><li>12 mm x 12 mm</li>
        </ul>
      </td>
    <td>1</td>
  </tr> 

</table>


## Épicas
<p>Pulsera de uso personal con multiples funciones que recopilan información relevante para el usuario.</p>
<p>Esta contendrá las siguientes funcionalidades:</p>
<ol>
  <li>Detección de temperatura y humedad.</li>
    <ul>
       <li>Mostrar datos capturados en pantalla OLED.</li>
      <li>Guardado de datos en Base de Datos.</li>
      <li>Desarrollo de aplicación web para mostrar datos.</li>
      <li>Mostrar datos en la aplicación.</li>
      <li>Alerta de sonido de buzzer ante altas o bajas temperaturas detectadas.</li>
    </ul>
  <li>Camara portable.</li>
    <ul>
      <li>Captura de imagen con cámara.</li>
      <li>Captura de archivo en formato de imagen.</li>
      <li>Guardado de archivo en cuenta de Google Drive.</li>
    </ul>
  <li>Pantalla OLED.</li>
    <ul>
      <li>Mostrar de datos obtenidos del sensor en pantalla.</li>
      <li>Mostrar imágenes en pantalla (opcional).</li>
    </ul>
  <li>Ritmo cardiaco.</li>
      <ul>
        <li>Mostrar datos capturados en pantalla OLED.</li>
        <li>Guardado de datos en Base de Datos.</li>
      <li>Desarrollo de aplicación web para mostrar datos.</li>
      <li>Mostrar datos en la aplicación.</li>
    </ul>
        <li>Detección de distancia.</li>
    <ul>
      <li>Mostrar datos capturados en pantalla OLED.</li>
      <li>Guardado de datos en Base de Datos.</li>
      <li>Desarrollo de aplicación web para mostrar datos.</li>
      <li>Mostrar datos en la aplicación.</li>
    </ul>
</ol>



## Requerimientos
<table>
  <tr>
    <th>No.</th>
      <th>Requerimiento</th>
  </tr>
  <tr>
    <td>1</td>
    <td>Medición de variables a partir de sensores de temperatura, humedad.</td>
  </tr>
  
  <tr>
    <td>2</td>
    <td>Almacenamiento de datos de manera continua y permanente.</td>
  </tr>
  
  <tr>
    <td>3</td>
    <td>Mostrar los datos en una panta OLED</td>
  </tr>
  
  <tr>
    <td>3</td>
    <td>Captura de foto y almacenarlas en la nube</td>
  </tr>
</table>


## Diagrama (Arquitectura)
<img width="100%" height="auto" alt="Diagrama_Pulsera Multiusos" src="https://github.com/SandraNAguayoN/wearable_equipo2/blob/main/img/diagrama.png">


## Prototipo de Pulsera Multiusos
![Prototipo_Pulsera Multiusos](https://github.com/SandraNAguayoN/wearable_equipo2/blob/main/img/dibujo_prototipo.jpg)

## Tablero
https://trello.com/b/qvzCt7Np/pulsera-multiusos
### Sprint 1
![Sprint1](https://github.com/SandraNAguayoN/wearable_equipo2/blob/main/img/tablero_sprint1.png)
### Sprint 2
![Sprint2](https://github.com/SandraNAguayoN/wearable_equipo2/blob/main/img/tablero_sprint2.png)
### Sprint 3
![Sprint3](https://github.com/SandraNAguayoN/wearable_equipo2/blob/main/img/tablero_sprint3.png)

## Resultados
VIDEO: https://drive.google.com/file/d/1Ioya-nBlbIvKEaiz-HuYXzhivvYoIGra/view?usp=sharing

## Participantes
* [Aguayo Nuñez Sandra ]()
* [Godínez Torres Juan Ramiro]()
* [Pérez Vega Noemi]()
* [Ramos Velázquez Carolina]()

[contribuidores-shield]: https://img.shields.io/github/contributors/github_username/repo_name.svg?style=for-the-badge
[contributors-url]: https://github.com/github_username/repo_name/graphs/contributors
