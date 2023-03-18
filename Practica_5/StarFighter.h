/** 
 * @file StarFighter.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef STARFIGHTER_H
#define STARFIGHTER_H

#include "Pieza.h"

#include <string>

const int MAX_PARTES = 50;

/**
 * @brief
 */
class StarFighter
{
   private:
      static int _numStarFighters; ///< Número de objetos de esta clase instanciados
      int _idSF=0; ///< Identificador único de la nave
      std::string _marca; ///< Marca de la nave (parece que las VW contaminan más)
      std::string _modelo; ///< Modelo de la nava
      int _numPlazas = 1; ///< Número de plazas de la nave
      int num_piezas = 1;
      Pieza **partes = nullptr;

   public:
      StarFighter ();
      StarFighter ( std::string marca, std::string modelo );
      StarFighter ( const StarFighter& orig );
      virtual ~StarFighter ( );
      StarFighter& setNumPlazas ( int numPlazas );
      int getNumPlazas ( ) const;
      StarFighter& setModelo ( std::string modelo );
      std::string getModelo ( ) const;
      StarFighter& setMarca ( std::string marca );
      std::string getMarca ( ) const;
      int getIdSF ( ) const;
      std::string toCSV () const;
      StarFighter& operator= ( const StarFighter& otro );
      void fromCSV ( std::string& datos );
      //Metodos de la prática 5
      void desplazaIzquierda(int posicion);
      void agnadirPieza(std::string nombre, float peso, std::string descripcion);
      void eliminarPieza(const Pieza &pieza);
      void eliminarPieza(std::string nombre);
};

#endif /* STARFIGHTER_H */

