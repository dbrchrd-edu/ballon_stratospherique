#include "GestionMesures.h"

GestionMesures::GestionMesures() : bme280(ADDRESS_BME280)
{
    // Mesures *mesures;

    /*  mpu6050 = new MPU6050();
      bme280 = new BME280(ADDRESS_BME280);
      lm75 = new LM75();
  */
    mpu6050.setAccSensibility(FS_2G);
}

GestionMesures::~GestionMesures()
{
}

void GestionMesures::effectuerMesures()
{
    /*accelerationVerticale = mpu6050.getAccelX();
    tempMpu = mpu6050.getTemperature();
    tempLm = lm75.getTemperature();
    tempBme = bme280.obtenirTemperatureEnC();
    // TOCHECK: temperature = (tempMpu * 0.3 + tempLm * 0.3 + tempBme * 0.4);
    temperature = tempBme;
    pression = bme280.obtenirPression();
    humidite = bme280.obtenirHumidite();*/

    setAccelerationVerticale(mpu6050.getAccelX());
    setTemperatureMpu(mpu6050.getTemperature());
    setTemperatureLm(lm75.getTemperature());
    setTemperatureBme(bme280.obtenirTemperatureEnC());
    setTemperature((tempMpu * 0.3 + tempLm * 0.3 + tempBme * 0.4));
    setPression(bme280.obtenirPression());
    setHumidite(bme280.obtenirHumidite());
}

bool GestionMesures::verifierMesures()
{
    bool valid = true;
    if (pression <= VAL_MIN_PRESSION || pression >= VAL_MAX_PRESSION)
    {
        valid = false;
        std::cerr << "La pression est invalide  : " << pression << " hPa" << std::endl;
    }
    if (humidite <= VAL_MIN_HUMIDITE || humidite >= VAL_MAX_HUMIDITE)
    {
        valid = false;
        std::cerr << "L'humidité est invalide : " << humidite << " %" << std::endl;
    }
    if (temperature <= VAL_MIN_TEMPERATURE || temperature >= VAL_MAX_TEMPERATURE)
    {
        valid = false;
        std::cerr << "La temperature est invalide : " << temperature << " °C" << std::endl;
    }
    if (accelerationVerticale <= VAL_MIN_ACCELERATION || accelerationVerticale >= VAL_MAX_ACCELERATION)
    {
        valid = false;
        std::cerr << "L'acceleration verticale est invalide : " << accelerationVerticale << " g" << std::endl;
    }

    return valid;
}

void GestionMesures::sauvegarderMesures()
{
    std::ofstream fichier("csv", std::ios_base::app);
    if (fichier.is_open())
    {
        std::time_t tempsActuel = std::time(nullptr);
        std::tm *tempsLocal = std::localtime(&tempsActuel);
        char timeStamp[20];
        std::strftime(timeStamp, sizeof(timeStamp), "%Y-%m-%d %H:%M:%S", tempsLocal);
        fichier << timeStamp << "," << temperature << "," << pression << "," << humidite << "," << accelerationVerticale << std::endl;
        fichier.close();
    }
    else
    {
        std::cerr << "Impossible d'ouvrir le fichier pour enregistrer les " << std::endl;
    }
}

double GestionMesures::getTemperature()
{
    return temperature;
}

double GestionMesures::getTemperatureMpu()
{
    return tempMpu;
}

double GestionMesures::getTemperatureLm()
{
    return tempLm;
}

double GestionMesures::getTemperatureBme()
{
    return tempBme;
}

double GestionMesures::getPression()
{
    return pression;
}

double GestionMesures::getHumidite()
{
    return humidite;
}

double GestionMesures::getAccelerationVerticale()
{
    return accelerationVerticale;
}

void GestionMesures::setTemperature(double temp)
{
    temperature = temp;
}

void GestionMesures::setTemperatureMpu(double temp)
{
    tempMpu = temp;
}

void GestionMesures::setTemperatureLm(double temp)
{
    tempLm = temp;
}

void GestionMesures::setTemperatureBme(double temp)
{
    tempBme = temp;
}

void GestionMesures::setPression(double press)
{
    pression = press;
}

void GestionMesures::setHumidite(double hum)
{
    humidite = hum;
}

void GestionMesures::setAccelerationVerticale(double acc)
{
    accelerationVerticale = acc;
}