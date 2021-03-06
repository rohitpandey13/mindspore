/**
 * Copyright 2020 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MINDSPORE_CCSRC_MINDDATA_DATASET_ENGINE_IR_DATASETOPS_BUILD_SENTENCE_PIECE_VOCAB_NODE_H_
#define MINDSPORE_CCSRC_MINDDATA_DATASET_ENGINE_IR_DATASETOPS_BUILD_SENTENCE_PIECE_VOCAB_NODE_H_

#include <memory>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>

#include "minddata/dataset/include/datasets.h"

namespace mindspore {
namespace dataset {

class BuildSentenceVocabNode : public DatasetNode {
 public:
  /// \brief Constructor
  BuildSentenceVocabNode(std::shared_ptr<DatasetNode> child, std::shared_ptr<SentencePieceVocab> vocab,
                         const std::vector<std::string> &col_names, uint32_t vocab_size, float character_coverage,
                         SentencePieceModel model_type, const std::unordered_map<std::string, std::string> &params);

  /// \brief Destructor
  ~BuildSentenceVocabNode() = default;

  /// \brief a base class override function to create the required runtime dataset op objects for this class
  /// \return The list of shared pointers to the newly created DatasetOps
  std::vector<std::shared_ptr<DatasetOp>> Build() override;

  /// \brief Parameters validation
  /// \return Status Status::OK() if all the parameters are valid
  Status ValidateParams() override;

 private:
  std::shared_ptr<SentencePieceVocab> vocab_;
  std::vector<std::string> col_names_;
  uint32_t vocab_size_;
  float character_coverage_;
  SentencePieceModel model_type_;
  std::unordered_map<std::string, std::string> params_;
};

}  // namespace dataset
}  // namespace mindspore
#endif  // #ifndef MINDSPORE_CCSRC_MINDDATA_DATASET_ENGINE_IR_DATASETOPS_BUILD_SENTENCE_PIECE_VOCAB_NODE_H_
