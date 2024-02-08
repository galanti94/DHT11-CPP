#include <util.h>

// Descrição completa da função prototipada na util.h
String outInfo(float humidity, float temperature, long initialTime)
{
  String info = "Humidade: ";
  info += humidity;
  info += " %";
  info += "; Temperatura: ";
  info += temperature;
  info += " ºC";
  info += "; Tempo: ";
  info += (millis() - initialTime) / 1000.0;
  info += " s";
  info += "\n";
  return info;
}