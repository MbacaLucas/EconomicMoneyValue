# 🇨🇱 Chile Economic Analyzer (consoleApp- not with API...yet )

Una herramienta de terminal interactiva diseñada para analizar la pérdida del poder adquisitivo y la situación laboral en Chile entre 2022 y 2026. Utiliza datos reales del **IPC (Índice de Precios al Consumidor)** y la **Tasa de Desempleo** proporcionados por el INE.

## 🚀 Características

- **Simulación de Inflación:** Calcula cuánto valdría tu dinero actual en años anteriores (2022-2025) basándose en puntos de índice IPC (Base 2023).
- **Análisis de Desempleo:** Compara la tasa de desocupación histórica con el escenario actual de 2026.
- **Precisión Financiera:** Manejo de precisión decimal para porcentajes y formato de enteros grandes (`long long`) para moneda nacional (CLP).
- **Validación de Datos:** Sistema de control mediante `switch` y variables "guardia" para prevenir errores de cálculo.

## 🛠️ Conceptos Técnicos Aplicados

- **Programación Modular:** Funciones independientes para cálculos matemáticos (`adjustedAmount`, `calculateInflationRate`).
- **Control de Flujo:** Uso de bucles `do-while` para sesiones persistentes y `switch-case` para selección de datos históricos.
- **Animación y Tiempo:** Uso de las librerías `<thread>` y `<chrono>` para gestionar la barra de carga en milisegundos.
- **Manipulación de Flujos:** Uso de `<iomanip>` (`fixed`, `setprecision`) y limpieza de búfer con `std::ws`.

## 📊 Ejemplo de Ejecución

```text
       Data Actualizada 2026 
====================================
IPC: 113.0pts   Desempleo: 8.0%
====================================
Ingresa cuanta plata tienes: 1000000
Ingresa el año de comparacion (ej: 2024): 2023

Cargando datos: [####################] 100%

-💰. Con $1000000 que tienes hoy en el 2026, en el año 2023 podias comprar lo mismo pero con $887610

-🇨🇱. Vivir hoy en chile es 12.7% mas caro

-⚠️. En 2023 habia un 8.7% de desempleo
        (0.7% mas alto que hoy)
