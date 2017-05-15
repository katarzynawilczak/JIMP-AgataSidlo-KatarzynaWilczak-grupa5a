#include <functional>
#include"Serialization.h"

namespace academia {

    std::string Room::NewEnumerableTypeToString(Room::Type type) const{
        switch (type) {
            case Room::Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Room::Type::CLASSROOM:
                return "CLASSROOM";
            case Room::Type::LECTURE_HALL:
                return "LECTURE_HALL";
        }
    }

    void Room::Serialize(Serializer *ptr) const{
        ptr->Header("room");
        ptr->IntegerField("id", id_);
        ptr->StringField("name", name_);
        ptr->StringField("type", NewEnumerableTypeToString(type_));
        ptr->Footer("room");

    }

    void Building::Serialize(Serializer *ptr) const{
        ptr->Header("building");
        ptr->IntegerField("id", id_);
        ptr->StringField("name", name_);
        ptr->ArrayField("rooms", rooms_);
        ptr->Footer("building");
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_ << "<" << object_name << ">";
    }

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        if (value == true) {
            *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
        } else
            *out_ << "<" << field_name << ">" << "<\\" << field_name << ">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const Serializable &value) {
        value.Serialize(this);
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const Serializable>> &value) {
        *out_ << "<" << field_name << ">";
         for (const Serializable &i : value){
             i.Serialize(this);
         }
        *out_ << "<\\"<< field_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_ << "<\\" << object_name << ">";
    }

    void JsonSerializer::Header(const std::string &object_name){
        *out_ <<"{";
        flagLastJsonValue=true;
    }
    void JsonSerializer::IntegerField(const std::string &field_name, int value){
        *out_ << "\"" << field_name << "\": " << value << ", ";
    }
    void JsonSerializer::DoubleField(const std::string &field_name, double value){
        *out_ << "\"" << field_name << "\": " << value << ", ";
    }
    void JsonSerializer::StringField(const std::string &field_name, const std::string &value){
        if (!flagLastJsonValue){
        *out_ << ", ";
        }
        *out_ << "\"" << field_name << "\": "<< "\"" << value << "\"";
        flagLastJsonValue=false;

    }
    void JsonSerializer::BooleanField(const std::string &field_name, bool value){
        if(value==true){
            *out_ << "\"" << field_name << "\": " << value << ", ";
        }
        else
            *out_ << "\"" << field_name << "\": , ";
    }
    void JsonSerializer::SerializableField(const std::string &field_name, const Serializable &value){
        value.Serialize(this);
    }
    void JsonSerializer::ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value){
        *out_ << ", \"" << field_name << "\": [";
        bool flagLastRoom=true;
        for(const Serializable &i: value){
            if(!flagLastRoom){
                *out_<<", ";
            }
            flagLastRoom=false;
            i.Serialize(this);
        }
        *out_<< "]";
    }
    void JsonSerializer::Footer(const std::string &object_name){
        *out_ <<"}";

    }
}
