//
// Created by stefan on 13/03/2023.
//

#ifndef PRACTICA_4_STARFIGHTER_H
#define PRACTICA_4_STARFIGHTER_H

//#include "Piloto.h"

/**
 * @brief
 */
class StarFighter
{
private:
    static int _numStarFighters; ///< Número de objetos de esta clase instanciados
    int _idSF = 1000 + _numStarFighters; ///< Identificador único de la nave
    std::string _marca; ///< Marca de la nave (parece que las VW contaminan más)
    std::string _modelo; ///< Modelo de la nava
    int _numPlazas; ///< Número de plazas de la nave
    //Piloto *piloto = nullptr;
    float parsecs = 0;
    bool libre = true;

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
    //StarFighter& setPiloto(Piloto *piloto);
    //Piloto& getPiloto() const;
    float getParsecs() const;
    void setLibre(bool libre);
    bool getLibre() const;
    void incrementarParsecs(float incremento);
    std::string toCSV () const;
    StarFighter& operator= ( const StarFighter& otro );

};

#endif //PRACTICA_4_STARFIGHTER_H
