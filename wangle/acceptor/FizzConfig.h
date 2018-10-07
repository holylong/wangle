/*
 * Copyright 2017-present Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <fizz/extensions/tokenbinding/Types.h>
#include <fizz/record/Types.h>

namespace wangle {

struct FizzConfig {
  bool enableFizz{false};
  std::vector<fizz::ProtocolVersion> supportedVersions;
  std::vector<std::vector<fizz::CipherSuite>> supportedCiphers;
  std::vector<fizz::SignatureScheme> supportedSigSchemes;
  std::vector<fizz::NamedGroup> supportedGroups;
  std::vector<fizz::PskKeyExchangeMode> supportedPskModes;
  bool acceptEarlyData{false};
  bool earlyDataFbOnly{false};

  folly::Optional<uint16_t> maxRecord;
  std::vector<fizz::CertificateCompressionAlgorithm> supportedCompressionAlgorithms;
};

struct FizzClientConfig {
  bool enableFizz{false};
  std::vector<fizz::ProtocolVersion> supportedVersions;
  std::vector<fizz::CipherSuite> supportedCiphers;
  std::vector<fizz::SignatureScheme> supportedSigSchemes;
  std::vector<fizz::NamedGroup> supportedGroups;
  std::vector<fizz::PskKeyExchangeMode> supportedPskModes;
  bool sendEarlyData{false};
};

struct TokenBindingConfig {
  bool enableTokenBinding{false};
  std::vector<fizz::extensions::TokenBindingProtocolVersion> supportedVersions;
  std::vector<fizz::extensions::TokenBindingKeyParameters>
      supportedKeyParameters;
};

} // namespace wangle
