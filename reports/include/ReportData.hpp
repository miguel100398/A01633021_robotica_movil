#ifndef REPORTDATA_HPP
#define REPORTDATA_HPP

#include <string>
#include <vector>
#include <iostream>
#include "CompareBehaviour.hpp"

template<typename T> class ReportData;
template<typename T> std::ostream& operator<<(std::ostream& os, const ReportData<T>& data);

template<typename T> class ReportData{
    private:
       template<typename K> class ReportRow{
            public:
                K key;
                std::string row;
                ReportRow(K key, std::string row);
        }; 
        std::vector< ReportRow<T> > reportrows;
        CompareBehaviour<T>* behaviour;
    public:
        ReportData(CompareBehaviour<T>* behaviour);
        ~ReportData();
        void add(T Key, std::string row);
        friend std::ostream& operator<< <> (std::ostream& os, const ReportData<T>& data);
};

template <typename T>
template <typename K>
ReportData<T>::ReportRow<K>::ReportRow(K key, std::string row){
    this->key = key;
    this->row = row;
}


template<typename T> ReportData<T>::ReportData(CompareBehaviour<T>* behaviour){
    this->behaviour = behaviour;
}

template<typename T> ReportData<T>::~ReportData(){
    //Delete report rows
    reportrows.clear();
}

template<typename T> void ReportData<T>::add(T Key, std::string row){
    //Create ReportRow
    typename std::vector<ReportRow<T>>::iterator it;
    ReportRow<T> newrow(Key, row);
    //newrow = new ReportRow<T>(Key, row);
    //First insertion
    if (reportrows.size() == 0){
        reportrows.push_back(newrow);
        return;
    }
    //Iterator points to begin
    
    it = reportrows.begin();

    for (it=reportrows.begin(); it<reportrows.end(); it++){
        if (!behaviour->compare(it->key, Key)){
            break;
        }
    }
    //Insert new row
    reportrows.insert(it, newrow);
}

template<typename T> std::ostream& operator<<(std::ostream& os, const ReportData<T>& data){
    for (int i=0; i<data.reportrows.size(); i++){
        os << data.reportrows[i].row << std::endl;
    }
    return os;
}

#endif //REPORTDATA_HPP