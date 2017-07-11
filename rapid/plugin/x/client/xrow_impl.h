/*
 * Copyright (c) 2015, 2017, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#ifndef X_CLIENT_XROW_IMPL_H_
#define X_CLIENT_XROW_IMPL_H_

#include <cstdint>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "message_holder.h"
#include "mysqlxclient/xrow.h"


namespace xcl {

class XRow_impl: public XRow {
 public:
  using Metadata = std::vector<Column_metadata>;

 public:
  explicit XRow_impl(Metadata *metadata);
  ~XRow_impl() override = default;

  int32_t get_number_of_fields() const override;
  bool valid() const override;

  bool is_null(const int32_t field_index) const override;
  bool get_int64(const int32_t field_index,
                 int64_t *out_data) const override;
  bool get_uint64(const int32_t field_index,
                  uint64_t *out_data) const override;
  bool get_double(const int32_t field_index,
                  double *out_data) const override;
  bool get_float(const int32_t field_index, float *out_data) const override;
  bool get_string(const int32_t field_index,
                  std::string *out_data) const override;
  bool get_string(const int32_t field_index,
                  const char **out_data,
                  size_t *out_data_length) const override;
  bool get_enum(const int32_t field_index,
                std::string *out_data) const override;
  bool get_enum(const int32_t field_index,
                const char **out_data,
                size_t *out_data_length) const override;
  bool get_decimal(const int32_t field_index, Decimal *out_data) const override;
  bool get_time(const int32_t field_index, Time *out_data) const override;
  bool get_datetime(const int32_t field_index,
                    DateTime *out_data) const override;
  bool get_set(const int32_t field_index,
               std::set<std::string> *out_data) const override;
  bool get_bit(const int32_t field_index, bool *out_data) const override;
  bool get_bit(const int32_t field_index, uint64_t *out_data) const override;

  bool get_field_as_string(const int32_t field_index,
                           std::string *out_data) const override;

  void clean();
  void set_row(std::unique_ptr<Row> &&row);

 private:
  bool get_string_based_field(const Column_type expected_type,
                              const int32_t field_index,
                              const char **out_data,
                              size_t *out_data_length) const;

  std::unique_ptr<Row> m_row;
  Metadata *m_metadata;
};

}  // namespace xcl

#endif  // X_CLIENT_XROW_IMPL_H_
