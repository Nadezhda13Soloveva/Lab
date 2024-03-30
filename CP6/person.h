#ifndef PERSON_H
#define PERSON_H


typedef struct _Person
{
    char surname[17];	// Фамилия
    char count_proc[3];     //Кол-во процессоров
    char type_proc[8];  //Тип процессора
    char memory[3];         //Объем памяти
    char type_video[15];    //Тип видеоконтроллера
    char videomemory[5];    //Объем видеопамяти
    char type_vin[5];   //Тип винчестера
    char count_vin[3];      //Кол-во винчестеров
    char volume_vin[5];     //Емкость винчестера
    char count_int[5];      //Кол-во интегрированных контроллеров
    char count_per[5];      //Кол-во периферийных устройств
    char system[10];    //Операционная система

} Person;

#endif