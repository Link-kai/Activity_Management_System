#include "../public.h"

//�޲ι��캯��
Activity::Activity() {}

//���ι��캯��
Activity::Activity(string id, const string &name, const string &content, const string &date, const string &location,
                   const string &requirement,int max_num_people, int state, const User &creator) : id(id), name(name),
                                                                                                   content(content), date(date),
                                                                                                   location(location),
                                                                                                   requirement(requirement), max_num_people(max_num_people),
                                                                                                   state(state), creator(creator) {}

//��������
Activity::~Activity() {

}