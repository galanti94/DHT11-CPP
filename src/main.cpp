#include <DHT.h>
#include <util.h>
#include <LiquidCrystal.h>

// Definindo o sensor DHT; Tive que apagar uma parte da biblioteca
#define DHTPIN A1
#define DHTTYPE DHT11

// Construindo o sensor
DHT dht(DHTPIN, DHTTYPE);

// LCD
const int RS = 12, EN = 11, D4 = 10, D5 = 9, D6 = 8, D7 = 7;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

// Definindo o tempo em que a placa iniciou; Será atualizada no setup
long initialTime;

void setup()
{  
  Serial.begin(9600);

  dht.begin(); // Iniciando o sensor
  lcd.begin(16, 2); // Iniciando o LCD

  lcd.clear(); // Limpando o LCD
  lcd.setCursor(0, 0); // Setando o cursor
  lcd.print("Teste"); // Teste de imagem

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