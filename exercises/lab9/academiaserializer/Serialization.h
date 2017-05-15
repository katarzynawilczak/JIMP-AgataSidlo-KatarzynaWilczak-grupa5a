
#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include<ostream>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <initializer_list>
#include <experimental/optional>

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

    protected:
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
        Building(int id, std::string name, std::vector<Room> rooms) : id_{id}, name_{name}, rooms_{rooms} {}
        int Id() const;
    private:
        int id_;
        std::string name_;
        std::vector<Room> rooms_;
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

    class BuildingRepository{
    public:
        BuildingRepository();
        BuildingRepository(const std::initializer_list<Building> &buildings);
        void StoreAll(Serializer* serializer) const;
        void Add(const Building &building);
        std::experimental::optional<Building> operator[](int id)const{
            for (auto &it: buildings_) {
                if (it.Id()==id) {
                    return std::experimental::make_optional(it);
                }
            }
            return std::experimental::optional<Building>();
        }
    private:
        std::vector<Building> buildings_;

    };

}

#endif //JIMP_EXERCISES_SERIALIZATION_H
