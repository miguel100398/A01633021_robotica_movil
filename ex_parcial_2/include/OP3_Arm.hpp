#ifndef OP3_ARM_HPP  
#define OP3_ARM_HPP

typedef struct coordinates_s {
    float x;
    float y;
    float z;
} coordinates_t;

typedef struct distance_s {
    float dx;
    float dy;
    float dz;
    float dist;
} distance_t;

class OP3_Arm {
    protected:
        coordinates_t coor_theta1;          //Coordinada theta 1
        coordinates_t coor_theta2;          //Coordinada theta 2    
        coordinates_t coor_theta3;          // Coordinada theta 3
        coordinates_t coor_end_efector;     //Coordinada efector final
        //Parametros constantes
        distance_t dis_w_p1;                //Distancia del punto w a punto 1
        distance_t dis_w_p2;                //Distancia del punto w a punto 2
        distance_t dis_w_p3;                //Distancia del punto w a punto 3

    public:
        OP3_Arm();      //Constructor default
        OP3_Arm(distance_t _dis_w_p1, distance_t _dis_w_p2, distance_t _dis_w_p3);  //Constructor indicando parametros constantes
        ~OP3_Arm();     //Destructor
        //Setters parametros constantes
        void set_dis_w_p1(distance_t _dis_w_p1);    
        void set_dis_w_p2(distance_t _dis_w_p2);
        void set_dis_w_p3(distance_t _dis_w_p3);
        //Getters parametros constantes
        distance_t get_dis_w_p1();
        distance_t get_dis_w_p2();
        distance_t get_dis_w_p3();
        void set_coor_end_efector(coordinates_t _coor_end_efector);       //Set coordinadas efector final
        coordinates_t get_coor_end_efector();           //get coordinates efector final
        //Setters coordinadas uniones
        void set_coor_theta1(coordinates_t _coor_theta1);
        void set_coor_theta2(coordinates_t _coor_theta2);
        void set_coor_theta3(coordinates_t _coor_theta3);
        //Getters coordinadas uniones
        coordinates_t get_coor_theta1();
        coordinates_t get_coor_theta2();
        coordinates_t get_coor_theta3();
        virtual void calculate_forward_kinematics();
        virtual void calculate_inverse_kinematics();

};

#endif //OP3_ARM_HPP