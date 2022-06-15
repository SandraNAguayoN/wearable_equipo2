# Proyecto Pulsera Multiuso
[![Contribuidores][contribuidores-shield]][contributors-url]

## contenido
<details>
  <summary>Tabla contenidos</summary>
  <ol>
    <li>
      <a href="#acerca-del-proyecto">Acerca Del Proyecto</a>
      <ul>
        <li><a href="#objetivo">Objetivo</a></li>
        <li><a href="#material-de-uso">Material de uso</a></li>
        <li><a href="#requerimientos">Requerimientos</a></li>
         <li><a href="#diagrama-inicial">Diagrama inicial</a></li>
      </ul>
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


### Objetivo

> .


### Material de uso:

<table> <tr> <th>Componente</th><th>Imagen</th><th>Descripción</th><th>Cantidad</th></tr>
  <tr>
    <td>Raspberry Pi 4</td>
    <td>
    <img src="https://user-images.githubusercontent.com/36056832/165995675-da53df0d-9c67-46af-94e3-22f30ad2aa4d.png" alt="Raspberry Pi 4" width="100"/>
    </td>
     <td><ul><li>Raspberry Pi 4 Modelo B 8GB RAM Original Uk.<li>Memoria microSD 32GB Clase 10 A1 con adaptador.<li>Cable microHDMI a HDMI 1.5m.<li>Carcasa con soporte para ventilador.<li>Ventilador 5VDC con tornillos y tuercas.<li>Fuente 5V 3A USB-C con Switch On/Off.<li>Kit de disipadores de calor cobre y aluminio con cinta térmica adherible.</ul></td>
    <td>1</td>
  </tr> 
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

</table>

#### Requerimientos
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
    <td>Captura de foto y almacenarlas de manera local</td>
  </tr>
</table>


<p>Pulsera de uso personal con multiples funciones que recopilan información relevante para el usuario.</p>
<p>Esta contendrá las siguientes funcionalidades:</p>
<ol>
  <li>Detección de temperatura y humedad.</li>
    <ul>
      <li>Medida de temperatura y humedad con el sensor</li>
      <li>Guardado de datos en Base de Datos.</li>
      <li>Desarrollo de aplicación web para mostrar datos.</li>
      <li>Mostrar datos en la aplicación.</li>
    </ul>
  <li>Camara portable.</li>
    <ul>
      <li>Captura de imagen con cámara.</li>
      <li>Captura de archivo en formato de imagen.</li>
      <li>Guardado de archivo en Memoria Micro SD.</li>
    </ul>
  <li>Pantalla OLED.</li>
    <ul>
      <li>Mostrar de datos obtenidos del sensor en pantalla.</li>
      <li>Mostrar imágenes en pantalla (opcional).</li>
    </ul>
  <li>Detección de oxigenación en la sangre.</li>
      <ul>
        <li>Detección de oxígeno en la sangre con sensor.</li>
        <li>Guardado de datos en Base de Datos.</li>
      <li>Desarrollo de aplicación web para mostrar datos.</li>
      <li>Mostrar datos en la aplicación.</li>
    </ul>
</ol>





### Diagrama inicial



### Prototipo de Pulsera Multiusos




## Participantes
* [Aguayo Nuñez Sandra ]()
* [Godínez Torres Juan Ramiro]()
* [Pérez Vega Noemi]()
* [Ramos Velázquez Carolina]()

[contribuidores-shield]: https://img.shields.io/github/contributors/github_username/repo_name.svg?style=for-the-badge
[contributors-url]: https://github.com/github_username/repo_name/graphs/contributors
