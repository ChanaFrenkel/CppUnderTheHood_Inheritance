//
// Created by chany on 6/16/20.
//

#include <stdio.h>
#include "2c_inheritance_defs.h"




void _Z11doMaterialsv()
{
    printf("\n--- Start doMaterials() ---\n\n") ;

    Materials mat;
    printf("Size of Materials: %lu\n", 1) ;
    printf("Size of mat: %lu\n", 1) ;
    printf("Size of Materials::Types: %lu\n", sizeof(enum Materials_Types)) ;
    printf("Size of Material_t: %lu\n", sizeof(Material_t)) ;

    struct { Materials mat; Material_t mat_t; }MatTest ;
    printf("Size of Materials + Material_t: %lu\n", 2*sizeof(Material_t)) ;

    Material_t mat1 , mat2 ;
    /*Material_t(Types mat = OTHER): material(mat) { printf("Material created, set to %s\n", name()); }*/
    /*const char* name() const { return getName(material); }*/
    /*static const char* getName(Types type)
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        return names[type];
    }*/
    {
        mat1.material = OTHER ;
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" } ;
        printf("Material created, set to %s\n", names[mat1.material]) ;
        mat2.material = METAL ;
        printf("Material created, set to %s\n", names[mat2.material]) ;

        printf("\n--- End doMaterials() ---\n\n") ;
    }

}

void _Z13doPhysicalBoxv()
{
    PhysicalBox pb1 ,pb2 ,pb3 ,pb4 ;
    printf("\n--- Start doPhysicalBox() ---\n\n") ;

    /*PhysicalBox pb1(8, 6, 4, Materials::PLASTIC);*/
    _ZS11PhysicalBox4ctordddMaterials_Types(&pb1 ,8 ,6 ,4 ,PLASTIC) ;
    /*PhysicalBox pb2(Materials::WOOD);*/
    _ZS11PhysicalBox4ctorMaterials_Types(&pb2 ,WOOD) ;
    /*PhysicalBox pb3(7, 7, 7);*/
    _ZS11PhysicalBox4ctrorddd(&pb3 ,7 ,7 ,7) ;

    printf("\npb4 is copy-constructed from pb1\n") ;
    /*PhysicalBox pb4 = pb1;*/
    Box (pb4) = Box(pb1) ;
    pb4.material.material = pb1.material.material ;

    /*pb4.printp();*/
    _ZS11PhysicalBox6printpv(&pb4) ;
    /*pb1.printp();*/
    _ZS11PhysicalBox6printpv(&pb1) ;

    /*printf("pb4 %s pb1\n", pb4 == pb1 ? "equals" : "does not equal");*/
    /*inline bool operator==(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
    return (const Box&)lhs == (const Box&)rhs && lhs.getMaterial() == rhs.getMaterial();
}*/
    /*inline bool operator==(const Box& lhs, const Box& rhs)
{
    return lhs.getWidth() == rhs.getWidth() && lhs.getHeight() == rhs.getHeight() && lhs.getLength() == rhs.getLength();
}*/

    printf("pb4 %s pb1\n", ( ( double(*(&pb4)) == double(*(&pb1))
    && double(*(&pb4 + sizeof(double))) == double(*(&pb1 + sizeof(double)))
    && double(*(&pb4 + 2 * sizeof(double)))  == double(*(&pb1 + 2 * sizeof(double)))  )
    && pb4.material.material == pb1.material.material ) ? "equals" : "does not equal") ;

    printf("\npb4 is copy-assigned from pb3\n") ;
    /*pb4 = pb3;*/
    Box (pb4) = Box(pb3) ;
    pb4.material.material = pb3.material.material ;
    /*pb4.printp();*/
    _ZS11PhysicalBox6printpv(&pb4) ;
    /*pb3.printp();*/
    _ZS11PhysicalBox6printpv(&pb3) ;
    printf("pb4 %s pb3\n",  ( ( double(*(&pb4)) == double(*(&pb3))
    && double(*(&pb4 + sizeof(double))) == double(*(&pb3 + sizeof(double)))
    && double(*(&pb4 + 2 * sizeof(double)))  == double(*(&pb3 + 2 * sizeof(double)))  )
    && pb4.material.material == pb3.material.material )   ? "equals" : "does not equal") ;

    printf("\n--- End doPhysicalBox() ---\n\n") ;
}

void _Z11doWeightBoxv()
{
    WeightBox pw1 ,pw2 ,pw3 ,pw4 ;
    printf("\n--- Start doWeightBox() ---\n\n") ;

    /*WeightBox pw1(8, 6, 4, 25);*/
    _ZS9WeightBox4ctordddd(&pw1 ,8 ,6 ,4 ,25) ;
    /*WeightBox pw2(1, 2, 3);*/
    _ZS9WeightBox4ctorddd(&pw2 ,1 ,2 ,3) ;
    /*WeightBox pw3(10, 20, 30, 15);*/
    _ZS9WeightBox4ctordddd(&pw3 ,10 ,20 ,30 ,15) ;

    printf("\npw4 is copy-constructed from pw1\n") ;
    /*WeightBox pw4 = pw1;*/
    _ZS9WeightBox8copyctorpc8WeightBox(&pw4 ,&pw1) ;
    /*pw4.printw();*/
    _ZS9WeightBox6printwv(&pw4) ;
    /*pw1.printw();*/
    _ZS9WeightBox6printwv(&pw1) ;
    /*printf("pw4 %s pw1\n", pw4 == pw1 ? "equals" : "does not equal");*/
    /*inline bool operator==(const WeightBox& lhs, const WeightBox& rhs)
{
    return (const Box&)lhs == (const Box&)rhs && lhs.getWeight() == rhs.getWeight();
}*/
    /*inline bool operator==(const Box& lhs, const Box& rhs)
{
    return lhs.getWidth() == rhs.getWidth() && lhs.getHeight() == rhs.getHeight() && lhs.getLength() == rhs.getLength();
}*/

    printf("pw4 %s pw1\n", ( ( double(*(&pw4)) == double(*(&pw1))
    && double(*(&pw4 + sizeof(double))) == double(*(&pw1 + sizeof(double)))
    && double(*(&pw4 + 2 * sizeof(double)))  == double(*(&pw1 + 2 * sizeof(double)))  )
    && pw4.weight == pw1.weight ) ? "equals" : "does not equal") ;

    printf("\npw4 is copy-assigned from pw3\n") ;
    /*pw4 = pw3;*/
    _ZS9WeighBox9operatoreqpcWeightBox(&pw4 ,&pw3) ;
    /*pw4.printw();*/
    _ZS9WeightBox6printwv(&pw4) ;
    /*pw3.printw();*/
    _ZS9WeightBox6printwv(&pw3) ;
    /*printf("pw4 %s pw3\n", pw4 == pw3 ? "equals" : "does not equal");*/
    printf("pw4 %s pw3\n", ( ( double(*(&pw4)) == double(*(&pw3))
    && double(*(&pw4 + sizeof(double))) == double(*(&pw3 + sizeof(double)))
    && double(*(&pw4 + 2 * sizeof(double)))  == double(*(&pw3 + 2 * sizeof(double)))  )
    && pw4.weight == pw3.weight ) ? "equals" : "does not equal") ;

    printf("\n--- End doWeightBox() ---\n\n") ;
}





int main()
{
    printf("\n--- Start main() ---\n\n") ;

    /*doMarerias();*/
    _Z11doMaterialsv() ;

    /*doPhysicalBox();*/
    _Z13doPhysicalBoxv() ;

    /*doWeightBox();*/
    _Z11doWeightBoxv() ;

    printf("\n--- End main() ---\n\n") ;

}

