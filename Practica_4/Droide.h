//
// Created by stefan on 13/03/2023.
//

#ifndef PRACTICA_4_DROIDE_H
#define PRACTICA_4_DROIDE_H

/**
 * @brief
 */
class Droide
{
private:
    static int _numDroides; ///< Número de droides instanciados
    int _idD = 0;           ///< Identificador del droide
    std::string _marca;     ///< Marca del droide
    std::string _modelo;    ///< Modelo de droide

public:
    Droide ( );
    Droide ( std::string marca, std::string modelo );
    Droide ( const Droide& orig );
    virtual ~Droide ( );
    int getIdD ( ) const;
    Droide& setModelo ( std::string modelo );
    std::string getModelo ( ) const;
    Droide& setMarca ( std::string marca );
    std::string getMarca ( ) const;
    std::string toCSV () const;
    Droide& operator= ( const Droide& otro );
};

#endif //PRACTICA_4_DROIDE_H
