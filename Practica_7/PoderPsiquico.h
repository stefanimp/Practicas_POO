/**
 * @file PoderPsiquico.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef PODERPSIQUICO_H
#define PODERPSIQUICO_H

#include "Poder.h"

/**
 * @brief
 */
class PoderPsiquico : public Poder
{
   public:
    //COnstantes
    const float MAX_LUCIDEZ = 1;
    const float MIN_LUCIDEZ = 0;

      PoderPsiquico ( ) = default;
    PoderPsiquico ( std::string nmb, std::string dsc, std::string aA, float cD);
      PoderPsiquico ( std::string nmb, std::string dsc, std::string aA, float cD,float lucidez);
      PoderPsiquico ( const PoderPsiquico& orig );
      virtual ~PoderPsiquico ( );
      PoderPsiquico& operator= ( const PoderPsiquico& orig );
      //Getters y setters creados por mi
      void setLucidez(float lucidez);
      float getLucidez() const;
      virtual float getCapacidadDestructiva() const override;
      //ToDo, redefinir toCSV y getCapacidadDestructiva (HECHO)
      virtual std::string toCSV() const override;

   private:
      //ToDo, añadir lucidez (HECHO)
      float lucidez = 0;
};

#endif /* PODERPSIQUICO_H */

