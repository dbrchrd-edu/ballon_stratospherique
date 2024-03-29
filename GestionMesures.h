#ifndef GESTIONMESURES_H
#define GESTIONMESURES_H

#include "MPU6050.h"
#include "LM75.h"
#include "BME280.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include <chrono>
#include <thread>

namespace
{
    const int ADDRESS_BME280 = 0x77;

    const double VAL_MIN_TEMPERATURE = -30.0;
    const double VAL_MAX_TEMPERATURE = 120.0;
    const double VAL_MIN_PRESSION = 800.0;
    const double VAL_MAX_PRESSION = 1200.0;
    const double VAL_MIN_HUMIDITE = 0.0;
    const double VAL_MAX_HUMIDITE = 100.0;
    const double VAL_MIN_ACCELERATION = -10.0;
    const double VAL_MAX_ACCELERATION = 10.0;
}

class GestionMesures
{
public:
    GestionMesures();
    ~GestionMesures();
    void effectuerMesures();
    bool verifierMesures();
    void sauvegarderMesures();

    // Assesseurs
    double getTemperature();
    double getTemperatureMpu();
    double getTemperatureLm();
    double getTemperatureBme();
    double getPression();
    double getHumidite();
    double getAccelerationVerticale();

    // Mutateurs
    void setTemperature(double temperature);
    void setTemperatureMpu(double temperatureMpu);
    void setTemperatureLm(double temperatureLm);
    void setTemperatureBme(double temperatureBme);
    void setPression(double pression);
    void setHumidite(double humidite);
    void setAccelerationVerticale(double accelerationVerticale);

private:
    double temperature;
    double tempMpu;
    double tempLm;
    double tempBme;
    double pression;
    double humidite;
    double accelerationVerticale;

    BME280 bme280;
    MPU6050 mpu6050;
    LM75 lm75;
};

#endif /* GESTIONMESURES_H */
