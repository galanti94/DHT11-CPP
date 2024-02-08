#include <DHT.h>
#include <util.h>

// Definindo o sensor DHT; Tive que apagar uma parte da biblioteca
#define DHTPIN A1
#define DHTTYPE DHT11

// Construindo o sensor
DHT dht(DHTPIN, DHTTYPE);

// Definindo o tempo em que a placa iniciou; Será atualizada no setup
long initialTime;

void setup()
{  
  Serial.begin(9600);
  dht.begin(); // Iniciando o sensor
  initialTime = millis(); // Tomando a referência de inicialização  
}

void loop()
{
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if ((millis() - initialTime) % 2000 == 0)
  {
    if (isnan(humidity) || isnan(temperature)) // Verifica se o leitor leu algo
    {
      Serial.println("Erro na leitura!");
    }
    else
    {
      Serial.println("Leitura do sensor:");
      Serial.println(outInfo(humidity, temperature, initialTime));
    }
  }
}