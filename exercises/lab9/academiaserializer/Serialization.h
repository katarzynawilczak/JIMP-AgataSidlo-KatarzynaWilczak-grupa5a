
#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include<ostream>
#include <iostream>
#include <vector>
#include <string>
#include <functional>


namespace academia {
    class Serializable;

    class Serializer{
    public:
        Serializer(std::ostream *out) : out_{out} {}
        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;
        std::ostream* out_;

    };

    class Serializable{
    public:
        virtual void Serialize(Serializer* ) const=0;
    };

    class Room : public Serializable {
    public:
        void Serialize(Serializer* ptr) const;
        enum class Type{
            COMPUTER_LAB,
            CLASSROOM,
            LECTURE_HALL,
        };
        std::string NewEnumerableTypeToString(Type type) const;
        Room(int id, const std::string name, Type type) : id_{id}, name_{name}, type_{type} {}
    private:
        int id_;
        const std::string name_;
        Type type_;

    };

    class Building : public Serializable{
    public:
        void Serialize(Serializer* ptr) const;
        Building(int id, const std::string name, const std::vector<std::reference_wrapper<const Serializable>> &rooms) : id_{id}, name_{name}, rooms_{rooms} {}

    private:
        int id_;
        const std::string name_;
        const std::vector<std::reference_wrapper<const Serializable>> rooms_;
    };

  class XmlSerializer : public Serializer{
    public:
      XmlSerializer(std::ostream* out) : Serializer(out) {}
      void IntegerField(const std::string &field_name, int value);
      void DoubleField(const std::string &field_name, double value);
      void StringField(const std::string &field_name, const std::string &value);
      void BooleanField(const std::string &field_name, bool value);
      void SerializableField(const std::string &field_name, const Serializable &value);
      void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value);
      void Header(const std::string &object_name);
      void Footer(const std::string &object_name);

    };

    class JsonSerializer : public Serializer{
    public:
        JsonSerializer(std::ostream* out) : Serializer(out) {}
        void IntegerField(const std::string &field_name, int value);
        void DoubleField(const std::string &field_name, double value);
        void StringField(const std::string &field_name, const std::string &value);
        void BooleanField(const std::string &field_name, bool value);
        void SerializableField(const std::string &field_name, const Serializable &value);
        void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value);
        void Header(const std::string &object_name);
        void Footer(const std::string &object_name);
    private:
        bool flagLastJsonValue;

    };

  //  class BuildingRepository{

    //};

}

#endif //JIMP_EXERCISES_SERIALIZATION_H
