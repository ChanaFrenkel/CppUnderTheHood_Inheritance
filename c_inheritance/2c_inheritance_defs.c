//
// Created by chany on 6/16/20.
//

#include <stdio.h>
#include "2c_inheritance_defs.h"


//// PhysicalBox Defs ////////////

void _ZS11PhysicalBox4ctorddd(PhysicalBox* const this , double l, double w, double h)
{
 _ZS3Box4ctorddd(&this ,l , w, h) ;
_ZS11PhysicalBox6printpv(this) ;
}

void _ZS11PhysicalBox4ctordddMaterials_Types(PhysicalBox* const this , double l, double w, double h, enum Materials_Types t)
{
    _ZS3Box4ctorddd(&this ,l , w, h) ;
    this->material.material = t ;
    _ZS11PhysicalBox6printpv(this) ;
}

void _ZS11PhysicalBox4ctorMaterials_Types(PhysicalBox* const this , enum Materials_Types t)
{
    _ZS3Box4ctorv(this) ;
    this->material.material = t ;
    _ZS11PhysicalBox6printpv(this) ;
}

void _ZS11PhysicalBox4dtorv(PhysicalBox* const this )
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", *(this), *(this + sizeof(double)), *(this + 2*sizeof(double )), names[this->material.material]);
    _ZS3Box4dtorv(this) ;
}

void _ZS11PhysicalBox6printpv(const PhysicalBox* const this)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox, made of %s; ", names[this->material.material]) ;
    _ZS3Box5printv(this) ;
}


/// WeightBox Defs ////////////

void _ZS9WeightBox4ctorddd(WeightBox* const this , double l, double w, double h)
{
    _ZS9WeightBox4ctordddd(this , l , w , h , 1.1) ;
}

void _ZS9WeightBox4ctordddd(WeightBox* const this ,double l, double w, double h, double wgt)
{
    _ZS3Box4ctorddd(this ,l ,w ,h) ;
    this->weight = wgt ;
    _ZS9WeightBox6printwv(this) ;
}

void _ZS9WeightBox8copyctorpc8WeightBox(WeightBox* const this ,const WeightBox* other)
{
    _ZS3Box4ctorv(this) ;
    this->weight = other->weight ;
    _ZS9WeightBox6printwv(this) ;
}

void _ZS9WeighBox4dtorv(WeightBox* const this )
{
    printf("Destructing WeightBox; ") ;
    _ZS9WeightBox6printwv(this) ;
    _ZS3Box4dtorv((Box*)(this)) ;
}

WeightBox*  _ZS9WeighBox9operatoreqpcWeightBox(WeightBox* const this , const WeightBox *other)
{
    *(Box*(this)) = *(Box*(other))
    this->weight = other->weight ;
    return this ;
}

void _ZS9WeightBox6printwv(const WeightBox* const this )
{
    printf("WeightBox, weight: %f; ", this->weight);
    _ZS3Box5printv(this) ;
}

