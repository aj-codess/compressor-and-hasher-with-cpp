#include <iostream>
#include <string>
#include <memory>
#include <zlib.h>
#include <vector>

#include <hasher.h>

using namespace std;

string reader(std::vector<unsigned char> x){
    std::unique_ptr<string> out=std::make_unique<string>();

    short i=0;

    while(i<x.size()){
        *out+=x.at(i);
        i++;
    };
    return *out;
};


string compressor(string data){

    std::unique_ptr<string> junk=std::make_unique<string>();

    std::unique_ptr<std::vector<unsigned char>> com_data=std::make_unique<std::vector<unsigned char>>();

    z_stream stream;
    memset(&stream,0,sizeof(stream));
    int* level=new int;
    *level=Z_DEFAULT_COMPRESSION;

    int* status=new int;
    *status=deflateInit(&stream,*level);

    if(*status != Z_OK){
        // "Error Compressing";
        compressor(data);
    };

    com_data->resize(compressBound(data.size()));


    stream.next_in = (Bytef *)data.data();
    stream.avail_in = (uInt)data.size();
    stream.next_out = com_data->data();
    stream.avail_out = com_data->size();


    *status = deflate(&stream, Z_FINISH);
    if (*status != Z_STREAM_END) {
        // "Compression Didnt complete";
         compressor(data);
    };

    deflateEnd(&stream);

    int* compressed_size=new int;
    *compressed_size = com_data->size() - stream.avail_out;
    com_data->push_back(*compressed_size);
    *junk=reader(*com_data);

    return *junk;
    delete compressed_size;
    delete status;
};


string hasher(string key){
    std::unique_ptr<string> message=std::make_unique<string>();

    *message=hasher_ref.hash(key);

    return *message;
};


int main(){
  std::string value_2_hash="Dark world";
  cout<<"Value after being compressed - "<<hasher(compressor(value_2_hash))<<endl;

  return 0;
}
