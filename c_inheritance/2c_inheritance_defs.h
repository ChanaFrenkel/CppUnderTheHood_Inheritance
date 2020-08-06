//
// Created by chany on 6/16/20.
//

#ifndef C___UNDER_THE_HOOD_2C_INHERITANCE_DEFS_H
#define C___UNDER_THE_HOOD_2C_INHERITANCE_DEFS_H

#include <stdio.h>
#include "2c_encapsulation_defs.h"

//// Materials ////////////

enum Materials_Types {
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
};

typedef struct {
} Materials;

typedef struct{
    enum Materials_Types material ;
}Material_t ;


//// PhysicalBox ////////////

typedef struct {
    Box ;
    Material_t material;
}PhysicalBox;

//// PhysicalBox Defs ////////////

/*in class: PhysicalBox(double l, double w, double h);*/
void _ZS11PhysicalBox4ctrorddd(PhysicalBox* const this , double l, double w, double h) ;
/*in class: PhysicalBox(double l, double w, double h, Materials::Types t);*/
void _ZS11PhysicalBox4ctordddMaterials_Types(PhysicalBox* const this , double l, double w, double h, enum Materials_Types t) ;
/*in class: PhysicalBox(Materials::Types t);*/
void _ZS11PhysicalBox4ctorMaterials_Types(PhysicalBox* const this  , enum Materials_Types t);
/*in class: ~PhysicalBox();*/
void _ZS11PhysicalBox4dtorv(PhysicalBox* const this ) ;
/*void printp() const;*/
void _ZS11PhysicalBox6printpv(const PhysicalBox* const this ) ;


//// WeightBox ////////////

typedef struct{
    Box  ;
    double weight;
}WeightBox;


//// WeightBox Defs ////////////

/*WeightBox(double l, double w, double h, double wgt = 0.0);*/
void _ZS9WeightBox4ctorddd(WeightBox* const this , double l, double w, double h) ;
void _ZS9WeightBox4ctordddd(WeightBox* const this ,double l, double w, double h, double wgt) ;
/*WeightBox(const WeightBox& other);*/
void _ZS9WeightBox8copyctorpc8WeightBox(WeightBox* const this ,const WeightBox* other) ;
/*~WeightBox();*/
void _ZS9WeighBox4dtorv(WeightBox* const this ) ;

/*WeightBox& operator=(const WeightBox& other);*/
WeightBox*  _ZS9WeighBox9operatoreqpcWeightBox(WeightBox* const this , const WeightBox *other) ;

/*void printw() const;*/
void _ZS9WeightBox6printwv(const WeightBox* const this ) ;


#endif /*C___UNDER_THE_HOOD_2C_INHERITANCE_DEFS_H*/
